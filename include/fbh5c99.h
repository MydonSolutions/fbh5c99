#ifndef FBH5_H
#define FBH5_H

#include "hdf5/serial/hdf5.h"
#include <string.h>
#include <stdlib.h>

#include "h5dsc99/h5_dataspace.h"

typedef struct
{
	double data_az_start;
	long data_barycentric;
	long data_data_type;
	double data_fch1;
	double data_foff;
	long data_ibeam;
	long data_machine_id;
	long data_nbeams;
	long data_nbits;
	long data_nchans;
	long data_nifs;
	long data_pulsarcentric;
	char* data_rawdatafile;
	char* data_source_name;
	double data_src_dej;
	double data_src_raj;
	long data_telescope_id;
	double data_tsamp;
	double data_tstart;
	double data_za_start;
} FBH5_attributes_t;

typedef struct
{
	hid_t file_id;
	FBH5_attributes_t attributes;
	H5_open_dataspace_t DS_data;
	void *data;
	H5_open_dataspace_t DS_mask;
	uint8_t *mask;
} FBH5_file_t;

void FBH5open(char* filepath, FBH5_file_t *FBH5file, hid_t Tdata);

void FBH5close(FBH5_file_t *FBH5file);

int FBH5write_dynamic(FBH5_file_t* FBH5file);

#endif