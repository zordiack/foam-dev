# foam-dev
OpenFOAM development and related scripts

The "utilities" sub folder contains some small bash scripts I have made for
myself and they are pretty self explanatory. To install, copy f.e.
into $FOAM_USER_APPBIN.

kOmegaSSTSASnew is a new version of SSTSAS implementation based on paper

Egorov, Y., & Menter F.R. (2009).
Formulation of of the Scale-Adaptive Simulation (SAS) Model during the
DESIDER Project.
DESider – A European Effort on Hybrid RANS-LES Modelling,
Notes on Num. Fluid Mech. And Multidisciplinary Design,
Volume 103, 19-67.

Additional omega and nut wall functions have been implemented, based on the
paper:

Knopp, T., Alrutz, T. and Schwamborn, D. (2006)
"A Grid and flow adaptive wall-function method for RANS turbulence
modelling"
Journal of Computational Physics,
Volume 220, 19-40

A version of chtMultiRegionFoam (and -SimpleFoam) including viscous heating
have been added. The new solvers are called chtMultiRegionFoamVH and
chtMultiRegionSimpleFoamVH.

To compile turbulence models and wall functions,
run ./Allwmake in folder myTurbulenceModels/.

To compile chtMultiRegionFoamVH, run ./Allwmake in folder mySolvers/.

To use kOmegaSSTSASnew, delta needs to be defined in
constant/turbulenceProperties:

```
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
```
..and the user compiled libs need to be added in system/controlDict
(choose appropriate version), libmyturbulenceModels is for wallFunctions:

```
libs
(
//    "libmyincompressibleturbulenceModels.so"
    "libmycompressibleturbulenceModels.so"
    "libmyturbulenceModels.so"
);
```
