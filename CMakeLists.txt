# Copyright 2016 Development Gateway, Inc
cmake_minimum_required(VERSION 2.8.11)
project(ldapescape C)

add_library(ldapescape STATIC escape.c)
set_target_properties(ldapescape PROPERTIES POSITION_INDEPENDENT_CODE true)
