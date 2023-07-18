#ifndef FBH5_H
#define FBH5_H

#include "hdf5/serial/hdf5.h"
#include <string.h>
#include <stdlib.h>

#include "h5dsc99/h5_dataspace.h"

typedef struct
{
  double az_start;
  long barycentric;
  long data_type;
  double fch1;
  double foff;
  long ibeam;
  long machine_id;
  long nbeams;
  long nbits;
  long nchans;
  long nifs;
  long pulsarcentric;
  char* rawdatafile;
  char* source_name;
  double src_dej;
  double src_raj;
  long telescope_id;
  double tsamp;
  double tstart;
  double za_start;
} FBH5_data_attributes_t;

typedef struct
{
  hid_t file_id;
  FBH5_data_attributes_t data_attributes;
  H5_open_dataspace_t DS_data;
  void *data;
  H5_open_dataspace_t DS_mask;
  uint8_t *mask;
} FBH5_file_t;

void FBH5open(char* filepath, FBH5_file_t *FBH5file, hid_t Tdata);

static inline void FBH5openFloat(char* filepath, FBH5_file_t *FBH5file) {
  return FBH5open(filepath, FBH5file, H5Tcopy(H5T_NATIVE_FLOAT));
}

static inline void FBH5openDouble(char* filepath, FBH5_file_t *FBH5file) {
  return FBH5open(filepath, FBH5file, H5Tcopy(H5T_NATIVE_DOUBLE));
}

void FBH5alloc(FBH5_file_t *FBH5file);

void FBH5clearAlloc(FBH5_file_t *FBH5file);

void FBH5free(FBH5_file_t *FBH5file);

void FBH5close(FBH5_file_t *FBH5file);

int FBH5write_dynamic(FBH5_file_t* FBH5file);

#endif