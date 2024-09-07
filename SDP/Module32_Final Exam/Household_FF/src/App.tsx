import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import './NavBar'
import {  BrowserRouter as Router, Route, Routes} from 'react-router-dom'
import NavBar from './NavBar'
import Registration from './auth/Registration'


function App() {
  return (
    <>
      <Router>
      <NavBar />
        <Routes>
          <Route path='register/' element={<Registration/>}/>
        </Routes>
      </Router>
    </>
  )
}

export default App
