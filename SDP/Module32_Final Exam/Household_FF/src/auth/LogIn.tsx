import axios from 'axios';
import React from 'react'
import { useForm } from 'react-hook-form';

interface LogInFormState{
	username: string,
	password: string
}

const  LogIn: React.FC= ()=> {
	const { register, handleSubmit, setError, formState: { errors } } = useForm<LogInFormState>()

	const onSubmit= async (data: LogInFormState) =>{
		try {
			const url = `http://127.0.0.1:8000/auth/login/`
			const response= await axios.post(url, data,{
				headers:{
					'Content-Type':'application/json'
				},
			})
			if(!response){
				console.log('no response');
				
			}
			else{
				console.log(response.data);
				
			}
		} catch (error) {
			throw error;
		}
	}

	return (
		<>
		<div>LogIn</div>

				<form className='w-96' onSubmit={handleSubmit(onSubmit)}>
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

					</div>
					<button type="submit" className="w-full mt-2 text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm w-full sm:w-auto px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Login</button>
				</form>
		</>
	)
}

export default LogIn