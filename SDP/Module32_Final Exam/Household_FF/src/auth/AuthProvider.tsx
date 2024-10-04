import React, { createContext, useState } from 'react'

const AuthContex= createContext({})
export const AuthProvider: React.FC =({children}:any)=>  {
	const [auth, setAuth] = useState()
	return (
		<AuthContex.Provider value={{auth, setAuth}}>
			{children}
		</AuthContex.Provider>
	)
}
