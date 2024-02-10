#!/usr/bin/env python3

import unittest
from math import sin, cos

from exercise01 import *


class Exercise01Tests(unittest.TestCase):

    def test_addi(self):
        self.assertEqual(addi(1, 2), 3)
        self.assertEqual(addi(100, -2), 98)

    def test_addf(self):
        self.assertAlmostEqual(addf(1.3, 4.3), 5.6)
        self.assertAlmostEqual(addf(0, 4.3), 4.3)

    def test_is_even(self):
        self.assertEqual(is_even(0), 1)
        self.assertEqual(is_even(-1), 0)
        self.assertEqual(is_even(1), 0)
        self.assertEqual(is_even(2), 1)

    def test_powerf(self):
        self.assertAlmostEqual(powerf(2, 4), 16)

    def test_factorial(self):
        self.assertEqual(factorial(0), 1)
        self.assertEqual(factorial(1), 1)
        self.assertEqual(factorial(2), 2)
        self.assertEqual(factorial(3), 6)
        self.assertEqual(factorial(8), 40320)

    def test_maclaurin_sin(self):
        self.assertAlmostEqual(maclaurin_sin(0, 7), sin(0))
        self.assertAlmostEqual(maclaurin_sin(0.1, 7), sin(0.1))
        self.assertAlmostEqual(maclaurin_sin(2, 7), sin(2))
        self.assertAlmostEqual(maclaurin_sin(3, 7), sin(3))
        self.assertAlmostEqual(maclaurin_sin(1.1, 7), sin(1.1))
        self.assertAlmostEqual(maclaurin_sin(4, 7), sin(4))

    def test_maclaurin_cos(self):
        self.assertAlmostEqual(maclaurin_cos(0, 7), cos(0))
        self.assertAlmostEqual(maclaurin_cos(0.1, 7), cos(0.1))
        self.assertAlmostEqual(maclaurin_cos(1.1, 7), cos(1.1))
        self.assertAlmostEqual(maclaurin_cos(3, 7), cos(3))
        self.assertAlmostEqual(maclaurin_cos(4, 7), cos(4))

    def test_fib(self):
        self.assertEqual(fib(0), 0)
        self.assertEqual(fib(1), 1)
        self.assertEqual(fib(2), 1)
        self.assertEqual(fib(3), 2)
        self.assertEqual(fib(4), 3)
        self.assertEqual(fib(5), 5)
        self.assertEqual(fib(6), 8)
        self.assertEqual(fib(19), 4181)
        self.assertEqual(fib(-1), 0)

    def test_string_to_int(self):
        self.assertEqual(string_to_int("123"), 123)
        self.assertEqual(string_to_int("-10"), -10)
        self.assertRaises(string_to_int("abc"), ValueError)

    def test_int_to_string(self):
        self.assertEqual(int_to_string(123), "123")
        self.assertEqual(int_to_string(-1), "-1")
        self.assertRaises(int_to_string("abc"), ValueError)
