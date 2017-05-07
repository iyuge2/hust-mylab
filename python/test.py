#!/usr/bin/env python3.5
# -*- coding: utf-8 -*-
height = float(input('input your height: '))
weight = float(input('input your weight: '))
Bmi = weight / (height * height)
if Bmi < 18.5:
    print('too light')
elif Bmi < 25:
    print('normal')
elif Bmi < 28:
    print('too heavy')
elif Bmi < 32:
    print('fat')
else:
    print('too fat')


































