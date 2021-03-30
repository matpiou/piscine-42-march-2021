#!/bin/sh
git status -s --ignored | grep "!!" | cut -c4-
