#!/bin/bash
#SBATCH --job-name=RunImage
#SBATCH --output=output_%j.txt
#SBATCH --error=error_%j.txt
#SBATCH --time=00:10:00
#SBATCH --ntasks-per-node=2
#SBATCH --cpus-per-task=1
#SBATCH --partition=g100_all_serial

#Commands to execute
singularity pull library://mayhem/prova/maxmult:latest
singularity run -C maxmult_latest.sif
rm maxmult_latest.sif
