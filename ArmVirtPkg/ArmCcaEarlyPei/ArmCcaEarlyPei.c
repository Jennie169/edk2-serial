/** @file
  Initialize the Realm Address Space in PEI phase, after the MMU was
  initialized.

  Copyright (c) 2022, Arm Limited. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <PiPei.h>

#include <Library/ArmCcaInitPeiLib.h>
#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>

/*++

Routine Description:



Arguments:

  FileHandle  - Handle of the file being invoked.
  PeiServices - Describes the list of possible PEI Services.

Returns:

  Status -  EFI_SUCCESS if the initialization was successful or skipped

--*/
EFI_STATUS
EFIAPI
ArmCcaEarlyPei(
  IN        EFI_PEI_FILE_HANDLE   FileHandle,
  IN CONST  EFI_PEI_SERVICES      **PeiServices
  )
{
  EFI_STATUS  Status;

  Status = ArmCcaConfigureSystemMemory();
  if (Status == RETURN_UNSUPPORTED) {
    return EFI_SUCCESS;
  }
  ASSERT_EFI_ERROR (Status);

  return Status;
}
