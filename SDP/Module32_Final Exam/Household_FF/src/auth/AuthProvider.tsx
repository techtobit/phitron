import React, { createContext, useState } from 'react'

const AuthContex= createContext({})
export const AuthProvider =({children}:any)=>  {
	const [auth, setAuth] = useState()
	return (
		<AuthContex.Provider value={{auth, setAuth}}>
			{children}
		</AuthContex.Provider>
	)
}

export default AuthContex;
