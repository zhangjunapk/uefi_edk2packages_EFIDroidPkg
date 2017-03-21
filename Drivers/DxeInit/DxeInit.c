/** @file
  Timer Architecture Protocol driver of the ARM flavor

  Copyright (c) 2011-2013 ARM Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/


#include <PiDxe.h>

#include <Library/DebugLib.h>
#include <Library/DxeInit.h>

EFI_STATUS
EFIAPI
DxeInitInitialize (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS Status;

  Status = LibChipVendorDxeInitialize (ImageHandle, SystemTable);
  ASSERT_RETURN_ERROR (Status);

  Status = LibPlatformDxeInitialize (ImageHandle, SystemTable);
  ASSERT_RETURN_ERROR (Status);

  return Status;
}

EFI_STATUS
EFIAPI
DxeInitPostGicInitialize (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS Status;

  Status = LibChipVendorDxePostGicInitialize (ImageHandle, SystemTable);
  ASSERT_RETURN_ERROR (Status);

  Status = LibPlatformDxePostGicInitialize (ImageHandle, SystemTable);
  ASSERT_RETURN_ERROR (Status);

  return Status;
}
