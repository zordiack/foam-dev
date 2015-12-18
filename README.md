# foam-dev
OpenFOAM development and related scripts

The "utilities" sub folder contains some small bash scripts I have made for
myself and they are pretty self explanatory. To install, copy f.e.
into $FOAM_USER_APPBIN.

kOmegaSSTSASnew is a new version of SSTSAS implementation, to compile 
run ./Allwmake.

To use kOmegaSSTSASnew, delta needs to be defined in
constant/turbulenceProperties:

`
RAS
{
    RASModel        kOmegaSSTSASnew;

    turbulence      on;

    printCoeffs     on;

    kOmegaSSTCoeffs
    {
        delta cubeRootVol;
        cubeRootVolCoeffs
        {}
    }
}
`
..and the user compiled libs need to be added in system/controlDict
(choose appropriate version):

`
libs
(
//    "libmyincompressibleturbulenceModels.so"
    "libmycompressibleturbulenceModels.so"
);
`
