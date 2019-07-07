"""
 Wiki:  A closure is a record storing a function[a] together with an environment.
 The environment is a mapping associating each free variable of the function
 (variables that are used locally, but defined in an enclosing scope) with the
 value or reference to which the name was bound when the closure was created.
 Unlike a plain function, a closure allows the function to access those captured
 variables through the closure's copies of their values or references, even when
 the function is invoked outside their scope.
"""

import logging

logging.basicConfig(filename='closure_example.log', level=logging.INFO)

def logger(func):
    def log_func(*args):
        logging.info('Running {} with arguments {}'.format(func.__name__, args))
        print(func(*args))
    return log_func

def mul(a, b):
    return a*b

def dev(a, b):
    return a/b

mul_logger = logger(mul)
dev_logger = logger(dev)

mul_logger(2,3)
dev_logger(6,2)
