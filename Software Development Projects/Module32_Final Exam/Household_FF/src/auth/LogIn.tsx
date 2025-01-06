import axios from 'axios';
import React from 'react'
import { useForm } from 'react-hook-form';
import { Link, useNavigate } from 'react-router-dom';

import {useAppDispatch } from '../redux/TypeHoock';
import { setAuthToken } from '../redux/Actions';




interface LogInFormState {
	username: string,
	password: string
}


const LogIn: React.FC = () => {
	const { register, handleSubmit, setError, formState: { errors } } = useForm<LogInFormState>()

	const dispatch = useAppDispatch() 


	const navigate = useNavigate()

	const onSubmit = async (data: LogInFormState) => {
		try {
			const url = `https://household-backend-a4k7.onrender.com/auth/login/`
			const response = await axios.post(url, data, {
				headers: {
					'Content-Type': 'application/json'
				},
			})
			if (response.status > 200) {
				setError( `root.${response.status}`, {
					type: response.statusText,
				})

			}
			else {

				const token = response?.data?.token;
				const user_id = response?.data?.user_id;
				localStorage.setItem('authToken', token)
				localStorage.setItem('user_id', user_id)
				dispatch(setAuthToken(token));
				navigate('/user/dashboard/');
				console.log(response);
				

			}
		} catch (error) {
			throw error;
		}
	}

	return (
		<div className='h-100vh w-full flex justify-center items-center content-center py-[8%]'>
			

			<form className='w-96 p-6 bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700' onSubmit={handleSubmit(onSubmit)}>
			<h5 className="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white  underline">Login</h5>
				<div>
					<div>
						<label htmlFor="username" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Username <span className='text-sm text-red-500'>*</span></label>
						<input
							id="username" type='text'
							{...register('username', { required: 'Username is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="jhone.dev11"
						/>
						{errors.username && <p className='text-sm text-red-500'>{errors.username.message}</p>}
					</div>

					<div>
						<label htmlFor="password" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Password <span className='text-sm text-red-500'>*</span></label>
						<input
							id="password" type='password'
							{...register('password', { required: 'password is required' })}
							className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="8736a#5V"
						/>
						{errors.password && <p className='text-sm text-red-500'>{errors.password.message}</p>}
					</div>

					<span className='text-[13px] font-normal '>Don't have an account? <Link to='/user/create/buyer_register/' className='underline text-blue-700 '>Create</Link> </span>
				</div>
				<button type="submit" className="w-full mt-2 text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm  px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Login</button>
			</form>
		</div>
	)
}

export default LogIn