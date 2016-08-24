[![Build Status](https://travis-ci.org/facontidavide/SuperPlotter.svg?branch=master)](https://travis-ci.org/facontidavide/SuperPlotter)

# PlotJuggler

QT5 based application to display time series in plots. This is under heavy development. 

To understand what PlotJuggler can do for you, take a look to the following video.

<iframe src="https://player.vimeo.com/video/174120477" width="640" height="360" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe> <p><a href="https://vimeo.com/174120477">PlotJuggler: a desktop application to plot time series.</a></p>

# How to build

First of all you need to clone the repository and its submodules either using the command:

      git clone --recursive https://github.com/facontidavide/PlotJuggler.git

or

      git clone https://github.com/facontidavide/PlotJuggler.git
      git submodule update --init --recursive


The only binary dependencies that you need installed on your system are Boost and Qt5. On Ubuntu the debans can be installed with the command:

    sudo apt-get -y install qtbase5-dev libboost-dev
    
The proceed as you would do with any cmake based project

    mkdir build; cd build
    cmake ..
    make