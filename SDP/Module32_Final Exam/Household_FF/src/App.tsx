
import './App.css'
import './NavBar'
import {  BrowserRouter as Router, Route, Routes} from 'react-router-dom'
import NavBar from './NavBar'
import Registration from './auth/Registration'
import Dashboard from './dashboard/Dashboard'
import ServicesList from './ServicesList'
import ServiceDetials from './ServiceDetials'
import CartList from './dashboard/CartList'
import LogIn from './auth/LogIn'
import PrivatRoute from './auth/PrivatRoute'
import HomeOutlet from './home/HomeOutlet'
import { Toaster } from 'react-hot-toast'
import ApiList from './utils/ApiList'



function App() {
  return (
    <>
      <Router>
      <NavBar />
        <Routes>
          <Route path='/' element={<HomeOutlet/>}/>
          <Route path='api_endpoints' element={<ApiList/>} />
          <Route path="/user/create/:registrationType"  element={<Registration/>}/>
          <Route path="/user/login/"  element={<LogIn/>}/>
          <Route element={<PrivatRoute/>}>
            <Route path='/user/dashboard/' element={<Dashboard/>}/>
          </Route>
          <Route path='services/' element={<ServicesList/>}/>
          <Route path='services/:id/' element={<ServiceDetials/>}/>
          <Route path='services/cartList/' element={<CartList/>}/>
        </Routes>
      </Router>
      <Toaster containerClassName='w-96 h-16 !left-[40%] '  />
    </>
  )
}

export default App
