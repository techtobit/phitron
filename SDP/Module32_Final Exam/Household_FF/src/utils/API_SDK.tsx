// import axios from "axios";

// const BASE_URL='https://household-backend-a4k7.onrender.com/';


// const apiClient = axios.create({
// 	baseURL: BASE_URL,
// 	headers: {
// 		'Content-Type' : 'application/json',
// 	}
// });


// // AUTH APIs 
// const login=(data:{username:string; password:string})=>{
// 	apiClient.post('auth/login/', data)
// }

// const registration=(registrationType:string, data:any)=>{
// 	apiClient.post(`/auth/${registrationType}/`, data)
// }

// const getSellerProfile=(username:string)=>{
// 	apiClient.get('auth/seller_profile/?username=${username}')
// }

// const getAllUsers=(data:any)=>{
// 	apiClient.get('auth/users/')
// }

// const getUserProfile=(user_id:number)=>{
// 	apiClient.get('auth/users/${user_id}/')
// }
// const userRoleUpdate=(id:number)=>{
// 	apiClient.get('/auth/users/${id}/update_role/')
// }



// export const apiSDK= {

// 	// AUTH 
// 	login,
// 	registration,
// 	getSellerProfile,
// 	getAllUsers,
// 	getUserProfile,
// 	userRoleUpdate
// };

