#include "fbh5c99.h"

herr_t _H5AwriteScalar(
	hid_t dest_id,
	char* name,
	hid_t H5T_id,
	void* value
) {
	hid_t A_id = H5Acreate2(
		dest_id,
		name,
		H5T_id,
		H5Screate(H5S_SCALAR),
		H5P_DEFAULT,
		H5P_DEFAULT
	);
	return H5Awrite(A_id, H5T_id, value);
}

void _FBH5writeAttributes(FBH5_file_t *FBH5file) {
	hid_t Tstr_id = H5Tcopy(H5T_C_S1);
	H5Tset_size(Tstr_id, 10);
	_H5AwriteScalar(
		FBH5file->file_id,
		"CLASS",
		Tstr_id,
		"FILTERBANK"
	);

	Tstr_id = H5Tcopy(H5T_C_S1);
	H5Tset_size(Tstr_id, 3);
	_H5AwriteScalar(
		FBH5file->file_id,
		"VERSION",
		Tstr_id,
		"1.0"
	);

	const char* data_dimension_labels[] = {
		"time",
		"feed_id",
		"frequency"
	};

	const hsize_t array_3[] = {3};
	hid_t S_id = H5Screate(H5S_SIMPLE);
  H5Sset_extent_simple(S_id, 1, array_3, NULL);
	hid_t T_id = H5Tcopy(H5T_C_S1);
	H5Tset_size(T_id, H5S_UNLIMITED);
  hid_t mask_dimlabels = H5Acreate2(
		FBH5file->DS_mask.D_id,
		"DIMENSION_LABELS",
		T_id,
		S_id,
		H5P_DEFAULT,
		H5P_DEFAULT
	);
  H5Awrite(mask_dimlabels, T_id, data_dimension_labels);
  hid_t data_dimlabels = H5Acreate2(
		FBH5file->DS_data.D_id,
		"DIMENSION_LABELS",
		T_id,
		S_id,
		H5P_DEFAULT,
		H5P_DEFAULT
	);
  H5Awrite(data_dimlabels, T_id, data_dimension_labels);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"az_start",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.az_start
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"barycentric",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.barycentric
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"data_type",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.data_type
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"fch1",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.fch1
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"foff",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.foff
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"ibeam",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.ibeam
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"machine_id",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.machine_id
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"nbeams",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.nbeams
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"nbits",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.nbits
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"nchans",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.nchans
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"nifs",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.nifs
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"pulsarcentric",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.pulsarcentric
	);
	
	Tstr_id = H5Tcopy(H5T_C_S1);
	H5Tset_size(Tstr_id, strlen(FBH5file->data_attributes.rawdatafile));
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"rawdatafile",
		Tstr_id,
		FBH5file->data_attributes.rawdatafile
	);
	
	Tstr_id = H5Tcopy(H5T_C_S1);
	H5Tset_size(Tstr_id, strlen(FBH5file->data_attributes.source_name));
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"source_name",
		Tstr_id,
		FBH5file->data_attributes.source_name
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"src_dej",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.src_dej
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"src_raj",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.src_raj
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"telescope_id",
		H5T_NATIVE_LONG,
		&FBH5file->data_attributes.telescope_id
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"tsamp",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.tsamp
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"tstart",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.tstart
	);
	
	_H5AwriteScalar(
		FBH5file->DS_data.D_id,
		"za_start",
		H5T_NATIVE_DOUBLE,
		&FBH5file->data_attributes.za_start
	);
}

void FBH5open(char* filepath, FBH5_file_t *FBH5file, hid_t Tdata) {
	FBH5file->file_id = H5Fcreate(filepath, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

	const hsize_t dim3_data_lim[] = {H5S_UNLIMITED, FBH5file->data_attributes.nifs, FBH5file->data_attributes.nchans};
	const hsize_t dim3_data_chunk[] = {1, FBH5file->data_attributes.nifs, FBH5file->data_attributes.nchans};

	FBH5file->DS_data.name = "data";
	H5DSset(3, dim3_data_lim, dim3_data_chunk, &FBH5file->DS_data);
	H5DSopen(FBH5file->file_id, Tdata, H5Tcopy(Tdata), &FBH5file->DS_data);
	FBH5file->data_attributes.nbits = H5Tget_size(FBH5file->DS_data.Tmem_id)*8;

	FBH5file->DS_mask.name = "mask";
	H5DSset(3, dim3_data_lim, dim3_data_chunk, &FBH5file->DS_mask);
	H5DSopen(FBH5file->file_id, H5Tcopy(H5T_STD_U8LE), H5Tcopy(H5T_STD_U8LE), &FBH5file->DS_mask);

	_FBH5writeAttributes(FBH5file);
}

void FBH5alloc(FBH5_file_t *FBH5file) {
	FBH5file->data = H5DSmalloc(&FBH5file->DS_data);
	FBH5file->mask = (uint8_t*) H5DSmalloc(&FBH5file->DS_mask);
}

void FBH5clearAlloc(FBH5_file_t *FBH5file) {
	memset(FBH5file->data, 0, H5DSsize(&FBH5file->DS_data));
	memset(FBH5file->mask, 0, H5DSsize(&FBH5file->DS_mask));
}

void FBH5close(FBH5_file_t *FBH5file) {
	H5DSclose(&FBH5file->DS_data);
	if (FBH5file->data != NULL) {
		free(FBH5file->data);
	}

	H5DSclose(&FBH5file->DS_mask);
	if (FBH5file->mask != NULL) {
		free(FBH5file->mask);
	}

	H5Fclose(FBH5file->file_id);
}

int FBH5write_dynamic(FBH5_file_t* FBH5file) {
	herr_t status;
	// data
	status = H5DSextend(&FBH5file->DS_data);
	if (status < 0) { fprintf(stderr, "Error (%s) H5DSextend failure on 'data'", __FUNCTION__); return -1;}
	status = H5DSwrite(&FBH5file->DS_data, FBH5file->data);
	if (status < 0) { fprintf(stderr, "Error (%s) H5DSwrite failure on 'data'", __FUNCTION__); return -1;}	

	// mask
	status = H5DSextend(&FBH5file->DS_mask);
	if (status < 0) { fprintf(stderr, "Error (%s) H5DSextend failure on 'mask'", __FUNCTION__); return -1;}
	status = H5DSwrite(&FBH5file->DS_mask, FBH5file->mask);
	if (status < 0) { fprintf(stderr, "Error (%s) H5DSwrite failure on 'mask'", __FUNCTION__); return -1;}	

	return 0;
}