class Person(object):
    def __init__(self, first, last):
        self.first = first
        self.last = last

    @property
    def email(self):
        return '{}_{}@gmail.com'.format(self.first, self.last)

    @property
    def fullname(self):
        return '{} {}'.format(self.first, self.last)

    @fullname.setter
    def fullname(self, name):
        self.first, self.last = name.split(' ')

    @fullname.deleter
    def fullname(self):
        print('Delter called for fullname')
        self.first = None
        self.last = None

p = Person('Virat', 'Kohli')
print(p.email)
print(p.fullname)
p.fullname = 'Rohit Sharma'
print(p.email)
print(p.fullname)
del p.fullname

