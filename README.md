## Overview

This repository is dedicated to steps two and three of the DevOps Project done in the Software Engineering for HPC course. It starts as an extension of the first part, in which we have implemented some tests for a matrix multiplication program, and then, focusing on a correct MPI-based implementation of the function, extends to cover more advanced DevOps practices, such as the automation of the entire push process, containerization of the program and its execution on the Galileo100 cluster, and to securely handle sensitive information required for authentication and transfer processes.

## Step 2 -- From build to release and manual job execution 

Focus now on the correct implementation of the matrix multiplication you
find in <https://github.com/SimoneReale/SE4HPC_project_part2>. This is a
parallel implementation that uses MPI and reads the matrices to be
multiplied from two files, matrixA.txt and matrixB.txt. In these files
the first row contains the matrix dimensions (number of rows and
columns), while the other rows contain the matrix itself.

Your task is to perform the following steps:

**Preparation**: Use the template available here
<https://github.com/SimoneReale/SE4HPC_project_part2> to create your own
github repository. Add to this repository the tests you have created in
Step1.

**Automating the build, test and release processes**: Create a CI/CD
pipeline that, when someone pushes files in the repo, executes the
building and testing process.

**Containerizing the application**: Go through the following steps:

-   Define a Singularity container descriptor for the matrix
    multiplication program and push it in your repo.

-   Extend the created action to create a container image from your
    description.

**Executing on the cluster**: Go through the following steps:

-   Create a job.sh file to run your containerized application. Make
    sure that the standard output and error are mapped to txt files.

-   Transfer on Galileo100 your job script and the container.

-   Submit your job to the cluster and check whether it works correctly.

-   Push on your github repository your job.sh file and the files
    obtained from the execution of the matrix multiplication.

## Step 3 -- Automating a job submission with containerization 

Extend the action you have created at step 3 to automate completely the
process from a push on the repository to the execution of the
containerized software on SLURM. To do so, you will have to move your
container from the runner to the cluster. You can either use the scp
command or you can publish your image on the Singularity registry and
then pull it from the cluster. Don't forget to handle your secrets
properly! You do not want to leave passwords and authentication tokens
visible to everybody, so you will use the [secrets
mechanism](https://docs.github.com/en/actions/security-guides/using-secrets-in-github-actions?tool=cli).


## ---------------------------------------------------------------------

# GITHUB ACTIONS
Github offers a service to perfom specific jobs when an event like pushing into the repo
by creating a file .yml inside the directory .github/workflows.
For this repo we defined 3 jobs on push events:
    1 - Compile and run tests
    2 - Create an image for the singularity container
    3 - Run the image on Galileo100 cluster

Jobs and the code they run can be found inside the ci.yml files

# 1 - Auto-run test
    A simple job that builds the project and runs the test, returns error if the tests'
    asserts find errors, helps to keep in check every push to found if new errors are being
    introduced in the program

# 2 - Building Singularity Image 
    Singularity is a containerization platform that allows to run code at high performance in an
    isolated enviroment, created and described by the container.def file.
    This command 
    ```
    sudo singularity build maxmult.sif container.def
    ```
    uses the .def file to create an image of it, which is the actual enviroment
    which offers scalability, security, portability(That we'll use to safely run the code on a cluster),
    and perfomance. The container is divided in  2 sectiond: %post with the commands to create a working image, and
    %runscript with the commands that will be ran by using singularity run
    ```
    singularity run maxmult.sif
    ```

    To do so automatically every time we push to have an updated image we need a github action
    that will install the singularity library in the github enviroment and than build the image

# 3 - Running the image on a cluster
    Since we want a cluster to execute our program (our image) we need to move it to the actual cluster.
    We send our image to a repo of the Singularity registry service by:
    ```
    touch sylabs-token
    echo "${{secrets.SYLABS_TOKEN}}" > sylabs-token
    singularity remote login --tokenfile sylabs-token
    ```
    First we login into our Sylabs account with a token stored in Github Secrets, then 
    ```
    singularity push -U maxmult.sif library://mayhem/prova/maxmult:latest
    ```
    We then can upload the image to a personal repository with the "latest" tag so that we will use the most
    recent image.
    Now we can let github log on the cluster to download the image
    ```
    sshpass -p ${{secrets.GALILEO_PW}} ssh -o StrictHostKeyChecking=no -t a08trb45@login.g100.cineca.it '
            wget https://raw.githubusercontent.com/Nizare7/SEHPC_DevOps_Part2_ElZiani_Fonnesu_Grassi/main/job.sh
            sbatch job.sh
            rm job.sh
            exit
          '
    ```
    We can connect to the cluster with the ssh and sshpass commands to access using the password
    which is again stored in Github Secrets, and using the -t flag we can write the commands to
    use on the cluster interactive terminal, which will just wget the job.sh from our repo
    and run it.
    Job.sh is just a simple script that will downlaod the latest image.sif stored in our Sylabs 
    repo ,run it and write the output and error in respective .txt files
    ```
    singularity pull library://mayhem/prova/maxmult:latest
    singularity run -C maxmult_latest.sif
    ```

# GITHUB CACHE
    Since the installation of singularity is long and costly, we saved it in the Github Cache
    system in a way such that every job that requires singularity will try to take singularity
    from cache and install it only in case of a cache miss.
    NB: Since we now install it to the cache location the singularity command in jobs is now replaced by the absolute 
    path :/opt/singularity/bin/singularity

# GITHUB SECRETS
    Every sensible information ( in this case the cluster password and the sylabs token) are stored
    in Github secrets, so that we don't leave private information to the public.
    Secrets are taken using ${{secrets.SECRET_NAME}}

PS: The Second job is overshadowed by the third job, since the jobs are run in parallel and
    we need the latest image uploaded on Singularity Registry before pulling it in the cluster,
    the last job builds again the image and uploads it, making the second job redudant, but we'll
    leave it for demonstrative purposes.
    
    
