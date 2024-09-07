
import './App.css'
import './NavBar'
import {  BrowserRouter as Router, Route, Routes} from 'react-router-dom'
import NavBar from './NavBar'
import Registration from './auth/Registration'
import Profile from './auth/Profile'
import ServicesList from './ServicesList'
import ServiceDetials from './ServiceDetials'


function App() {
  return (
    <>
      <Router>
      <NavBar />
        <Routes>
          <Route path="/auth/:registrationType/"  element={<Registration/>}/>
          <Route path='/auth/profile/' element={<Profile/>}/>
          <Route path='services/' element={<ServicesList/>}/>
          <Route path='services/:id' element={<ServiceDetials/>}/>
        </Routes>
      </Router>
    </>
  )
}

export default App
