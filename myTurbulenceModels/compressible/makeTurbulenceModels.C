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

#include "../turbulenceModels/RAS/kOmegaSSTSASnew/kOmegaSSTSASnew.H"
makeTemplatedTurbulenceModel
(
    fluidThermoCompressibleTurbulenceModel,
    RAS,
    kOmegaSSTSASnew
);
