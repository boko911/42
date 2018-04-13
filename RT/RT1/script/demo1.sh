#!/bin/bash
./rt -w 1 -h 1 cor/1_scp &
./rt -w 1200 -h 1 -t 6 cor/2_texture  &
./rt -w 1 -h 740 -t 6 cor/3_box  &
./rt -w 1200 -h 740 -t 6 cor/4_pertu  &
