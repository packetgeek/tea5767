# fmradio
Control software for the TEA5767 and RDA5807SP in TEA5767 mode, on the Raspberry Pi, using the wiringPi library.

Controls include:

- mute.c - mutes the audio output
- searchdn.c - searches for the next station downward
- searchup.c - searches for the next station upward
- status.c - reports on frequency and if stereo is being rec'd
- tune.c - tunes the radio to a specific frequency (e.g., 98.7)
- unmute.c - unmutes the audio output

Read the source for each to determine how to compile them.

The wiringPi library is at: http://wiringpi.com/

Tim (17 Jan 2015)
