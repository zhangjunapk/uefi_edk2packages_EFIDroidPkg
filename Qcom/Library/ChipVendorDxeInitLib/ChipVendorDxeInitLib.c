#include <PiDxe.h>

EFI_STATUS
EFIAPI
LibChipVendorDxeInitialize (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
LibChipVendorDxePostGicInitialize (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  return EFI_SUCCESS;
}
