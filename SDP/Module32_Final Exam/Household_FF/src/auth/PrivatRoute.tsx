import React, { useContext } from 'react'
import AuthContex from './AuthProvider'
import { Navigate, Outlet } from 'react-router-dom'

const PrivatRoute:React.FC=()=> {
	const{auth}:any = useContext(AuthContex)
	console.log('auth', auth);
	
	if(!auth) return <Navigate to='/auth/login/' replace />

	return (<Outlet/>)
}

export default PrivatRoute