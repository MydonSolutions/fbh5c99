# Filterbank HDF5 C99 Library

Writes filterbank data to an HDF5 file.

Blimpy's `watutil -i` prints out the following given the test generated `.fbh5` file:

```
--- File Info ---
DIMENSION_LABELS :   ['time' 'feed_id' 'frequency']
        az_start :                             0.45
     barycentric :                                0
       data_type :                                0
            fch1 :                       1420.0 MHz
            foff :                       0.0625 MHz
           ibeam :                                0
      machine_id :                                9
          nbeams :                                1
           nbits :                               32
          nchans :                              128
            nifs :                                1
   pulsarcentric :                                0
     rawdatafile :                   not applicable
     source_name :                   not applicable
         src_dej :                      1:34:14.862
         src_raj :                      0:47:07.431
    telescope_id :                                9
           tsamp :                          1.6e-05
   tstart (ISOT) :          2023-07-15T00:00:00.000
    tstart (MJD) :                          60140.0
        za_start :                             0.42

Num ints in file :                                3
      File shape :                      (3, 1, 128)
--- Selection Info ---
Data selection shape :                      (3, 1, 128)
Minimum freq (MHz) :                           1420.0
Maximum freq (MHz) :                        1427.9375
```

## Building

Uses `meson` and `ninja`, typically acquired via `pip`.

```
$ meson setup build && cd build
build $ ninja test && ninja install
```
