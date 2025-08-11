#! /bin/bash

# ######################################################################## #
# File:     adjust_tags.sh
#
# Purpose:  COMPLETE_ME
#
# Created:  21st May 2025
# Updated:  21st May 2025
#
# Author:   Matthew Wilson
#
# Copyright (c) Matthew Wilson, COMPLETE_ME
# All rights reserved
#
# ######################################################################## #

# git tag -a 1.10.0-rc1 1.10-rc1 -m tag

git tag -a 1.10.0-alpha1 1.10.1-alpha1 -m tag ; git tag -d 1.10.1-alpha1
git tag -a 1.10.0-alpha3 1.10.1-alpha3 -m tag ; git tag -d 1.10.1-alpha3
git tag -a 1.10.0-alpha5 1.10.1-alpha5 -m tag ; git tag -d 1.10.1-alpha5
git tag -a 1.10.0-alpha6 1.10.1-alpha6 -m tag ; git tag -d 1.10.1-alpha6
git tag -a 1.10.0-alpha7 1.10.1-alpha7 -m tag ; git tag -d 1.10.1-alpha7
git tag -a 1.10.0-alpha8 1.10.1-alpha8 -m tag ; git tag -d 1.10.1-alpha8
git tag -a 1.10.0-alpha9 1.10.1-alpha9 -m tag ; git tag -d 1.10.1-alpha9
git tag -a 1.10.0-beta1 1.10.1-beta1 -m tag ; git tag -d 1.10.1-beta1
git tag -a 1.10.0-beta2 1.10.1-beta2 -m tag ; git tag -d 1.10.1-beta2
git tag -a 1.10.0-beta3 1.10.1-beta3 -m tag ; git tag -d 1.10.1-beta3
git tag -a 1.10.0-beta4 1.10.1-beta4 -m tag ; git tag -d 1.10.1-beta4
git tag -a 1.10.0-beta5 1.10.1-beta5 -m tag ; git tag -d 1.10.1-beta5
git tag -a 1.10.0-beta6 1.10.1-beta6 -m tag ; git tag -d 1.10.1-beta6

