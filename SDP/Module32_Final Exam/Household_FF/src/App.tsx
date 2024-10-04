
import './App.css'
import './NavBar'
import {  BrowserRouter as Router, Route, Routes} from 'react-router-dom'
import NavBar from './NavBar'
import Registration from './auth/Registration'
import Profile from './auth/Profile'
import ServicesList from './ServicesList'
import ServiceDetials from './ServiceDetials'
import CartList from './CartList'
import LogIn from './auth/LogIn'
import PrivatRoute from './auth/PrivatRoute'


function App() {
  return (
    <>
      <Router>
      <NavBar />
        <Routes>
          <Route path="/auth/:registrationType/"  element={<Registration/>}/>
          <Route path="/auth/login/"  element={<LogIn/>}/>
          <Route element={<PrivatRoute/>}>
            <Route path='/auth/profile/' element={<Profile/>}/>
          </Route>
          <Route path='services/' element={<ServicesList/>}/>
          <Route path='services/:id' element={<ServiceDetials/>}/>
          <Route path='services/cartList/' element={<CartList/>}/>
        </Routes>
      </Router>
    </>
  )
}

export default App
