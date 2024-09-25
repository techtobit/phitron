import React from 'react'
import { Navigate, Outlet } from 'react-router-dom'
import {useAppSelector } from '../redux/TypeHoock';

const PrivatRoute:React.FC=()=> {

	const authToken = useAppSelector((state) => state.auth.token)
	
	if(!authToken) return <Navigate to='/user/login/' replace />

	return (<Outlet/>)
}

export default PrivatRoute