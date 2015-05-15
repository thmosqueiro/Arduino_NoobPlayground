Leaky Integratino
===

The idea is to develop a leaky integrate-and-fire neuron module with
temperature dependence and a current clamp.

<img src="https://raw.githubusercontent.com/thmosqueiro/PlaygroundINO/master/Medium-Projects/LeakyIntegratino/images/LeakyIntegratino.png" width=400px style="display: block; margin: 10px auto 10px auto;" />
<img src="https://raw.githubusercontent.com/thmosqueiro/PlaygroundINO/master/Medium-Projects/LeakyIntegratino/images/Temperature+Noise_effects.png" width=400px style="display: block; margin: 10px auto 10px auto;" />


The current is controlled by a simple (four-legs) switch. It's
amplitued is controlled via software and read through a digital
pin. To easily identify spikes (and for debug purposes), I've used a
red LED.

<img src="https://raw.githubusercontent.com/thmosqueiro/PlaygroundINO/master/Medium-Projects/LeakyIntegratino/images/IMG_20150510_183327.jpg" width=400px style="display: block; margin: 10px auto 10px auto;" />



Usage
---

Just upload the .ino code into arduino, mount a simple circuit (see
below the simple schematics) and use the python companion script to
plot it on your computer.


<img src="https://github.com/thmosqueiro/PlaygroundINO/blob/master/Medium-Projects/LeakyIntegratino/images/LIFino_schematics.png" width=400px style="display: block; margin: 10px auto 10px auto;" />
