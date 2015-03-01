# fmradio
Control software for the TEA5767 and RDA5807SP in TEA5767 mode, on the Raspberry Pi, using the wiringPi library.

Controls include:

- mute.c - mutes the audio output
- searchdn.c - searches for the next station downward (currently doesn't work on TEA5767)
- searchup.c - searches for the next station upward (currently doesn't work on TEA5767)
- status.c - reports on frequency and if stereo is being rec'd
- tune.c - tunes the radio to a specific frequency (e.g., 98.7)
- unmute.c - unmutes the audio output

Read the source for each to determine how to compile them.

The wiringPi library is at: http://wiringpi.com/

Known issues:  The search function does not work on the TEA5767 breakout boards.  The chip's spec sheet explains that this limitation is caused by the cheap external watch crystal that's used on the breakout board.  The same spec sheet recommends implementing the search function in software.  I've done this and will upload the code shortly.

Update (1 Mar 2015): I'm currently working on removing the dependency on the wiringPi library.
