#include "fbh5c99.h"

int main() {

  FBH5_file_t fbh5_file;

  fbh5_file.data_attributes.az_start = 0.45;
  fbh5_file.data_attributes.barycentric = 0;
  fbh5_file.data_attributes.data_type = 0;
  fbh5_file.data_attributes.fch1 = 1420.0;
  fbh5_file.data_attributes.foff = 1.0/16.0;
  fbh5_file.data_attributes.ibeam = 0;
  fbh5_file.data_attributes.machine_id = 9;
  fbh5_file.data_attributes.nbeams = 1;
  fbh5_file.data_attributes.nchans = 16*8;
  fbh5_file.data_attributes.nifs = 1;
  fbh5_file.data_attributes.pulsarcentric = 0;
  fbh5_file.data_attributes.rawdatafile = NULL;
  fbh5_file.data_attributes.source_name = "not applicable";
  fbh5_file.data_attributes.src_dej = 3.14159/2;
  fbh5_file.data_attributes.src_raj = 3.14159/4;
  fbh5_file.data_attributes.telescope_id = 9;
  fbh5_file.data_attributes.tsamp = 16.0/1000000.0;
  fbh5_file.data_attributes.tstart = 60140.0;
  fbh5_file.data_attributes.za_start = 0.42;

  // shorthand for FBH5open("test.fbh5", &fbh5_file, H5Tcopy(H5T_NATIVE_FLOAT));
  FBH5openFloat("test.fbh5", &fbh5_file);
  // allocate the data and mask pointers, then clear them
  FBH5alloc(&fbh5_file);
  FBH5clearAlloc(&fbh5_file);

  FBH5write_dynamic(&fbh5_file);
  FBH5write_dynamic(&fbh5_file);
  FBH5write_dynamic(&fbh5_file);

  FBH5close(&fbh5_file);
  FBH5free(&fbh5_file);

  return 0;
}
