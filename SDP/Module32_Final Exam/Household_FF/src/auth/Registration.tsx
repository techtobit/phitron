import axios from 'axios';
import React, { useState } from 'react'
import { useForm } from 'react-hook-form';

interface RegistrationFromState {
	username: string,
	first_name: string,
	last_name: string,
	email: string,
	password: string,
}

const Registration: React.FC = () => {

	const{register,  handleSubmit, setError, formState:{errors}}=useForm<RegistrationFromState>()
	
	const onSubmit= async (data:RegistrationFromState)=>{
		try {
			const response= await axios.post('http://127.0.0.1:8000/auth/buyer_register/', data, {
				headers:{
					"Content-Type": "application/json"
				},
			})
			console.log('response-', response.data);

		} catch (error:any) {
			console.error('error-', error);
		}
	}

	return (
		<div>
			<form onSubmit={ handleSubmit(onSubmit)}>
				<div className="grid gap-6 mb-6 md:grid-cols-1">
					<div>
						<label htmlFor="username" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Username</label>
						<input
							id="username" type='text'
							{...register('username', { required: 'Username is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="jhone.dev11" 
						/>
						{errors.username && <p>{errors.username.message}</p>}
					</div>
					<div>
						<label htmlFor="first_name" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">First Name</label>
						<input
							id="first_name" type='text'
							{...register('first_name', { required: 'First Name is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="David" 
						/>
						{errors.first_name && <p>{errors.first_name.message}</p>}
					</div>
					<div>
						<label htmlFor="last_name" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Last Name</label>
						<input
							id="last_name" type='text'
							{...register('last_name', { required: 'Last Name is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Warner" 
						/>
						{errors.last_name && <p>{errors.last_name.message}</p>}
					</div>
					<div>
						<label htmlFor="email" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Email</label>
						<input
							id="email" type='email'
							{...register('email', { required: 'Email is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="david@gamil.com" 
						/>
						{errors.email && <p>{errors.email.message}</p>}
					</div>
					<div>
						<label htmlFor="password" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Password</label>
						<input
							id="password" type='password'
							{...register('password', { required: 'password is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="8736a#5V" 
						/>
						{errors.password && <p>{errors.password.message}</p>}
					</div>
				</div>

				<button type="submit" className="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm w-full sm:w-auto px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Submit</button>
			</form>

		</div>
	)
}

export default Registration;