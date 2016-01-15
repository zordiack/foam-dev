#include "turbulentFluidThermoModel.H"
#include "addToRunTimeSelectionTable.H"
#include "makeTurbulenceModel.H"

namespace Foam
{

typedef ThermalDiffusivity<CompressibleTurbulenceModel<fluidThermo> >
    fluidThermoCompressibleTurbulenceModel;

typedef RASModel<EddyDiffusivity<fluidThermoCompressibleTurbulenceModel> >
    RASfluidThermoCompressibleTurbulenceModel;

}

#include "kOmegaSSTSASnew.H"
makeTemplatedTurbulenceModel
(
    fluidThermoCompressibleTurbulenceModel,
    RAS,
    kOmegaSSTSASnew
);
