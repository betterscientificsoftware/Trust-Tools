#(1) Pull parent image.
From ubuntu:18.04

# (2) Set environment variables.
ENV DEBIAN_FRONTEND=noninteractive

# (3) Download software dependencies.
RUN yes| apt-get update && yes| apt-get install g++ && yes | apt-get install git && yes | apt-get install texlive-latex-recommended && yes | apt-get install texlive-publishers && yes | apt-get install python3.6

