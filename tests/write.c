#include "fbh5c99.h"

int main() {

	FBH5_file_t fbh5_file;

	fbh5_file.attributes.data_az_start = 0.45;
	fbh5_file.attributes.data_barycentric = 0;
	fbh5_file.attributes.data_data_type = 0;
	fbh5_file.attributes.data_fch1 = 1420.0;
	fbh5_file.attributes.data_foff = 1.0/16.0;
	fbh5_file.attributes.data_ibeam = 0;
	fbh5_file.attributes.data_machine_id = 9;
	fbh5_file.attributes.data_nbeams = 1;
	fbh5_file.attributes.data_nchans = 16*8;
	fbh5_file.attributes.data_nifs = 1;
	fbh5_file.attributes.data_pulsarcentric = 0;
	fbh5_file.attributes.data_rawdatafile = "not applicable";
	fbh5_file.attributes.data_source_name = "not applicable";
	fbh5_file.attributes.data_src_dej = 3.14159/2;
	fbh5_file.attributes.data_src_raj = 3.14159/4;
	fbh5_file.attributes.data_telescope_id = 9;
	fbh5_file.attributes.data_tsamp = 16.0/1000000.0;
	fbh5_file.attributes.data_tstart = 60140.0;
	fbh5_file.attributes.data_za_start = 0.42;

	FBH5open("test.fbh5", &fbh5_file, H5Tcopy(H5T_NATIVE_FLOAT));

	FBH5write_dynamic(&fbh5_file);
	FBH5write_dynamic(&fbh5_file);
	FBH5write_dynamic(&fbh5_file);

	FBH5close(&fbh5_file);

	return 0;
}
