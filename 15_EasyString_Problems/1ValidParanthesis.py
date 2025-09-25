class Animal:
    def __init__(self, name,breed, age):
        
        self.name= name      # public attribute 
        self._breed = breed  # protected attribute
        self.__age = age   # private attribute


    def display_age(self):
        print(f"The age of the animal is {self.__age}")    # accessing private attribute within class method

    def display_info(self):
        print(f"Name: {self.name}, Breed: {self._breed}, Age: {self.__age}")  # accessing all attributes within class method




    

class Dog(Animal):
    
    def __init__(self,name, breed, age):
        super().__init__(name, breed, age)


    def display_name(self):
        print(f"The name of the dog is {self.name}")
    
    def display_breed(self):
        print(f"The breed of the dog is {self._breed}")

    
    def display_age(self):
        print(f'The age of the dog is {super().__init__(self.__age)}') 

    def display_name(self):
        print(f"The name of the dog is {self.name}")
    
    def display_breed(self):
        print(f"The breed of the dog is {self._breed}")

    # name mangling
    def display_age(self):
        print(f'The age of the dog is {self._Animal__age}')  # accessing private attribute of parent class using name mangling
                


d1 = Dog("Buddy", "Golden Retriever", 3)
d1.display_age()       
d1.display_info()
d1.display_name()
d1.display_breed()   
d1.display_age()     # accessing private attribute of parent class using name mangling