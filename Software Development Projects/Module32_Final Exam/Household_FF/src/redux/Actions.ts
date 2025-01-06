
export const setAuthToken=(token:string|null)=>({
	type: 'SET_AUTH_TOKEN',
	payload : token
})