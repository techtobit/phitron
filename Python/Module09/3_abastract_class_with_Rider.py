from abc import ABC, abstractmethod
class User(ABC):
    def __init__(self, name, email, nid):
        self.name = name
        self.email = email
        #TODO : set user is dynamically
        self.__id = 0
        self.__nid = nid
        self.wallet = 0

    @abstractmethod
    def display_profile(self):
        raise NotADirectoryError
    
class Rider(User):
    def __init__(self, name, email, nid) -> None:
        super().__init__(name, email, nid)
    
    def display_profile(self):
        print(f'Rider: with name: {self.name} and email: {self.email}')
    
    def request_ride(self, location, destination):
        if not self.current_ride:
            #Todo : set ride properly
            ride_request = None 
