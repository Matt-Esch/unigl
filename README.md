## unigl

WORK IN PROGRESS.


## Rationale

Today it is possible to build cross-platform games and apps using a variety of
technologies. Many game engines provide abstractions that compile down to
different targets and the web provides multiple cross-platform options.

The caveat with all of these choices is that you either:

  - have to build on top of an existing heavy abstraction such as a game engine

  - produce oversized binaries that are not portable or easily debuggable (browser wrappers)


I want to be able to build cross-platform applications easily and with a
tiny footprint.

Where I would like to begin to solve this problem is by creating a stand-alone
cross-platform GLES 2.0 compliant window and context. Essentially this is like
extracting out the features of WebGL and making them stand-alone. It's important
to target direct3D on Windows for example, simply because driver support is
better on average. ANGLE will be used as it is in chromium for translating
GLES 2.0 to direct3D.

For this to be usable, there will need to be additional cross-platform modules
for input and output, and the idea is that these features will be completely
modular and included by the user when required.

Finally, there will be an attempt to pair this with Golang, depending on how
easy it is to cross-compile Golang for Windows/Mac/Linux/Android/iOS/web.
