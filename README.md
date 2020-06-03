## Documentation for Trust Tools
### March Madness Simulator

Each reproducible solution is applied to a sports ranking simulation based on the 1998 undergraduate thesis of Kenneth Massey. The application uses historical game data and linear algebra to predict the placement of teams in the NCAA basketball tournament. The application takes one parameter, the additional points added to teams playing away from home. The experiment will vary this parameter and assess its effect on the accuracy of the simulated team ranking.

To run the simulation, pull source code from Trust-Tools and compile. CMake can be used for compilation. After compiling the source code, ```./March_Madness_Simulator # ``` will produce a ranking with a value of ```#``` added to the score of teams not playing at home.

### Script Workflow
The script workflow represents the simplest reproducibility workflow. This solution runs the March Madness simulator on the host machine and generates a paper with simulated results. To execute this experiment run ```./script/run.sh```. The following software packages must be installed before running the experiment.

```
git
CMake
install texlive-latex-recommended
install texlive-publishers 
python3.6
```

### Docker Workflow
A Docker workflow alleviates potential dependency problems present in a script workflow. The following demonstrates running March Madness simulator Docker workflow and creating a reproducible workflow with Docker.
### Run Docker Solution
Before executing this solution, install Docker. Up-to-date directions can be found on the [Docker homepage](https://docs.docker.com/get-docker/). Next, navigate to docker directory in cloned Trust Tools repository. The image representing this experiment is built and executed with ```docker build .``` and ```docker run <image_id>``` respectively. Executing the image will produce a container with instructions for running simulation and generating paper.
### Create Your Own
The environment of an experiment is described in a Dockerfile. Below is a template Dockerfile.
### Dockerfile Example:
```
From <Base Image>

RUN <Install Dependecies>    

CMD <Terminal Commands>
```

### Popper Workflow
A Popper workflow builds upon a container workflow, like Docker. This solution allows for automated verification and validation testing. The following demonstrates running the March Madness simulator Popper workflow and creating a Popper compliant experiment.
Run Popper Solution
Popper must be installed before executing this workflow. Updated, system-specific installation information can be found on the  [Popper homepage](https://falsifiable.us/). After installing Popper, navigate to ```popper``` directory in the cloned Trust Tools repository. Run the following command to execute the experiment; ```popper run -f wf.yml```. This will execute all steps in ```wf.yml``` file.
### Create Your Own
A Popper workflow enumerates each step of the experiment in a Ain't Markup Language (YAML) file entitled ```wf.yml```. Below is an example ```wf.yml``` file.

### Popper ```wf.yml``` file Example:

```
steps:

- uses: </Path/To/Container>
  args: './Path/To/Script'
  
  or

- uses: </Path/To/Container>
  runs: ['./Path/To/Script','<Argument>']

```
