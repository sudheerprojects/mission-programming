#Decorator using function decorator
def display_decorator(original_display):
    def wrapper_function(*args, **kwargs):
        print('     Wrapper executed for {}'.format(original_display.__name__))
        return original_display(*args, **kwargs)
    return wrapper_function

@display_decorator
def display():
    print("This is simple display function")

@display_decorator
def display_info(name, age):
    print("     Display info: name {} and age {}".format(name, age))

print("Decorator using function decorator:")
display()
display_info('Adam', 30)

#Decorator using class decorator
class decorator_class(object):
    def __init__(self, original_function):
        self.original_function = original_function

    def __call__(self, *args, **kwargs):
        print('     Call method executed for {}'.format(self.original_function.__name__))
        self.original_function(*args, **kwargs)

@decorator_class
def display():
    print("     This is simple display function")

@decorator_class
def display_info(name, age):
    print("     Display info: name {} and age {}".format(name, age))

print('Decorator using class decorator:')
display()
display_info('Eve', 30)

#Practical example of decorator
from functools import wraps
def my_logger(original_function):
    import logging
    logging.basicConfig(filename='{}.log'.format(original_function.__name__), level=logging.INFO)

    @wraps(original_function)
    def wrapper(*args, **kwargs):
        logging.info('{} Ran with: args {}, and kwargs {}'.format(original_function.__name__, args, kwargs))
        return original_function(*args, **kwargs)
    return wrapper

def my_timer(original_function):
    import time

    @wraps(original_function)
    def wrapper(*args, **kwargs):
        t1 = time.time()
        result = original_function(*args, **kwargs)
        print('     {} ran in: {} sec'.format(original_function.__name__, time.time() - t1))
        return result
    return wrapper

@my_timer
@my_logger
def display_info(name, age):
    print("     Display info: name {} and age {}".format(name, age))

print('Practical example of decorator')
display_info('Eve', 23)


