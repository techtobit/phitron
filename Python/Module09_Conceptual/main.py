from abc import ABC, abstractmethod
class Ride_Sharing:
    def __init__(self, company_name) -> None:
        self.company_name = company_name
        self.riders=[]
        self.drivers=[]
    def add_drivers(self, driver):
        self.drivers.append(driver)
    def add_riders(self, rider):
        self.riders.append(rider)
    

class User(ABC):
    def __init__(self, name, email, nid) -> None:
        self.name = name
        self.email = email
        self.nid = nid
    @abstractmethod

    def dispaly_profile(self):
        raise NotImplementedError
    
class Driver(User):
    def __init__(self, name, email, nid, current_location) -> None:
        super().__init__(name, email, nid)
        self.current_location = current_location

    def dispaly_profile(self):
        print(f'Driver name is {self.name} and email is {self.email}')
    
class Rider(User):
    def __init__(self, name, email, nid, current_location) -> None:
        super().__init__(name, email, nid)
        self.current_location = current_location
        self.current_ride = None
    def dispaly_profile(self):
        print(f'Driver name is {self.name} and email is {self.email}')
    def ride_request(self, uber, destination):
        if not self.current_ride:
            ob=Ride_Matching(uber.drivers)
            res = ob.has_driver(self, des
                                tination)
            print('Ride Found', res)
            self.current_ride = res

class Ride:
    def __init__(self, start_location, end_location) -> None:
        self.start_location=start_location
        self.end_location = end_location
        self.driver = None
        self.rider = None
    def start_ride(self):
        pass
    def end_ride(self):
        pass

    def __repr__(self) -> str:
        return f'start from {self.start_location} to {self.end_location}'
    

class Ride_Matching:
    def __init__(self, drivers) -> None:
        self.drivers = drivers
    def has_driver(self,rider, destination):
        if len(self.drivers) > 0 :
            ride = Ride(rider.current_location, destination)
            return ride
        else:
            return 'Driver Not Found'


uber = Ride_Sharing("UBER")
xnone = Driver('Xnone', 'xonne@dr.com', 9356, 'chittagong shadar')
alex = Rider('Alex', 'alex@gmail.com', 6348, 'chittagong port')

uber.add_drivers(xnone)
uber.add_riders(alex)

alex.ride_request(uber, 'Dhaka')