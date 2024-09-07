
import './App.css'
import './NavBar'
import {  BrowserRouter as Router, Route, Routes} from 'react-router-dom'
import NavBar from './NavBar'
import Registration from './auth/Registration'
import Profile from './auth/Profile'
import Services from './Services'


function App() {
  return (
    <>
      <Router>
      <NavBar />
        <Routes>
          <Route path="/auth/:registrationType/"  element={<Registration/>}/>
          <Route path='/auth/profile/' element={<Profile/>}/>
          <Route path='service/' element={<Services/>}/>
        </Routes>
      </Router>
    </>
  )
}

export default App
