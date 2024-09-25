import axios from 'axios';
import { useForm } from 'react-hook-form';
import { Link, useNavigate, useParams } from 'react-router-dom';
import sellerBlob from '../assets/seller.png'
import buyerBlob from '../assets/buyer.png'
import toast from 'react-hot-toast';

interface RegistrationFromState {
	username: string,
	first_name: string,
	last_name: string,
	email: string,
	account_type: string,
	password: string,

}

const Registration: React.FC = () => {
	
	const { register, handleSubmit, setError, formState: { errors } } = useForm<RegistrationFromState>()
	//takeing Registration Type from URL
	const { registrationType } = useParams<{ registrationType: string }>();
	const navigate = useNavigate()

	
	const onSubmit = async (data: RegistrationFromState) => {
		try {
			const response = await axios.post(`https://household-backend-a4k7.onrender.com/auth/${registrationType}/`, data, {
				headers: {
					"Content-Type": "application/json"
				},
			})
			console.log('response-', response.data);
			toast.success('Account Created Successfully')
			navigate('/user/login/');
			const backendErrors = response.data;
			Object.keys(backendErrors).forEach((fields) => {
				setError(fields as keyof RegistrationFromState, {
					type: 'server',
					message: backendErrors[fields][0]
				})
			})


		} catch (error: any) {
			toast.error('Failed To Account Create',  error.message)
			console.error('Error:', error.message);
		}
	};


	return (
		<div className='grid gap-6 mx-10 grid-cols-2 justify-center items-center justify-items-center bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700'>

			{registrationType === 'seller_register' ?
				<img className='w-96' src={sellerBlob} alt="" />
				:
				<img className='w-[60rem]' src={buyerBlob} alt="" />
			}
			<div>
				<h1 className='py-4 text-lg text-2xl font-bold tracking-tight text-gray-900 dark:text-white  underline '>{registrationType == 'buyer_register' ? 'Create Client(Buyer) Account' : 'Create Service Provier Account'}</h1>
				<form className='w-96 pb-4' onSubmit={handleSubmit(onSubmit)}>
					<div>
						<div>
							<label htmlFor="username" className="block  text-sm font-medium text-gray-900 dark:text-white">Username <span className='text-sm text-red-500'>*</span></label>
							<input
								id="username" type='text'
								{...register('username', { required: 'Username is required' })}
								className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="jhone.dev11"
							/>
							{errors.username && <p className='text-[13px] text-red-500'>{errors.username.message}</p>}
						</div>
						<div>
							<label htmlFor="first_name" className="block mt-2 text-sm font-medium text-gray-900 dark:text-white">First Name <span className='text-sm text-red-500'>*</span></label>
							<input
								id="first_name" type='text'
								{...register('first_name', { required: 'First Name is required' })}
								className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="David"
							/>
							{errors.first_name && <p className='text-[13px] text-red-500'>{errors.first_name.message}</p>}
						</div>
						<div>
							<label htmlFor="last_name" className="block mt-2 text-sm font-medium text-gray-900 dark:text-white">Last Name <span className='text-sm text-red-500'>*</span></label>
							<input
								id="last_name" type='text'
								{...register('last_name', { required: 'Last Name is required' })}
								className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Warner"
							/>
							{errors.last_name && <p className='text-[13px] text-red-500'>{errors.last_name.message}</p>}
						</div>
						<div>
							<label htmlFor="email" className="block mt-2 text-sm font-medium text-gray-900 dark:text-white">Email <span className='text-sm text-red-500'>*</span></label>
							<input
								id="email" type='email'
								{...register('email', { required: 'Email is required' })}
								className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="david@gamil.com"
							/>
							{errors.email && <p className='text-[13px] text-red-500'>{errors.email.message}</p>}
						</div>
						{/* <div>
							<label htmlFor="account_type" className="block mt-2 text-sm font-medium text-gray-900 dark:text-white">Account Type <span className='text-sm text-red-500'>*</span></label>
							<input
								id="account_type" type='text' disabled value={registrationType}
								{...register('account_type', { required: 'Last Name is required' })}
								className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder={registrationType}
							/>
							{errors.last_name && <p className='text-[13px] text-red-500'>{errors.last_name.message}</p>}
						</div> */}
						<div>
							<label htmlFor="password" className="block mt-2 text-sm font-medium text-gray-900 dark:text-white">Password <span className='text-sm text-red-500'>*</span></label>
							<input
								id="password" type='password'
								{...register('password', { required: 'password is required' })}
								className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="8736a#5V"
							/>
							{errors.password && <p className='text-[13px] text-red-500'>{errors.password.message}</p>}
						</div>
						<span className='text-[13px] font-normal '>Alrady have account? <Link to='/user/login/' className='underline text-blue-700 '>Login</Link> </span>
					</div>
					<button type="submit" className="w-full mt-2 text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm  px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Registration</button>

				</form>



				{registrationType == "buyer_register" ?
					<Link to="/user/create/seller_register/" className="w-full inline-block text-center focus:outline-none text-white bg-yellow-400 hover:bg-yellow-500 focus:ring-4 focus:ring-yellow-300 font-medium rounded-lg text-sm px-5 py-2.5 me-2 mb-2 dark:focus:ring-yellow-900">
						Join As Service Provider
					</Link>
					:
					<Link to="/user/create/buyer_register/" className="w-full inline-block text-center sfocus:outline-none text-white bg-purple-700 hover:bg-purple-800 focus:ring-4 focus:ring-purple-300 font-medium rounded-lg text-sm px-5 py-2.5 mb-2 dark:bg-purple-600 dark:hover:bg-purple-700 dark:focus:ring-purple-900">
						Join As Client
					</Link>


				}

			</div>
		</div >
	)
}


export default Registration;