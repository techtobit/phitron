import axios from 'axios';
import React, { useEffect, useState } from 'react'
import CartList from './CartList';
import RadialChart from './RadialChart';
import LevelsChart from './LevelsChart';
import { AiOutlineShopping, AiOutlineShoppingCart, AiFillInfoCircle, AiTwotoneAppstore, AiOutlineUsergroupAdd, AiFillShopping } from "react-icons/ai";
import Users from './Users';
import Products from './Products';
import Orders from './Orders';
import {  useAppSelector } from '../redux/TypeHoock';
import { setAuthToken } from '../redux/Actions';
import logo from '../assets/hs.png';
import { useDispatch, useSelector } from 'react-redux';
import { RootState } from '../redux/Store';
import { setDashboardBtnActive, setDashboardAsideBtn } from '../redux/dashboardSlice';


interface userDataType {
	username: string,
	first_name: string,
	last_name: string,
	email: string,
	is_staff: boolean,
	is_superuser: boolean,
	is_active: boolean,
	date_joined: any,
	last_login: any,

}


const Dashboard: React.FC = () => {

  const dispatch = useDispatch()
  const activeAsideBtn = useSelector((state: RootState)=> state.dashboard.activeAsideBtn)
	const authToken = useAppSelector((state) => state.auth.token)
	const token = null;
	const [profileData, setProfileData] = useState<userDataType>()
	const user_id = localStorage.getItem('user_id')



  const handleDashboardBtn=()=>{
    dispatch(setDashboardBtnActive(true))
  }


	const toggleAsideNav = (clickedCompo: string) => {
		dispatch(setDashboardAsideBtn(clickedCompo))
		// setasideNavItem(clickedCompo)
	}




	const getProfileData = async () => {
		try {
			const response = await axios.get(`https://household-backend-a4k7.onrender.com/auth/users/${user_id}/`)
			setProfileData(response.data)

		} catch (error) {
			console.log(error);

		}
	}


	useEffect(() => {
		getProfileData();

	}, [user_id])




	const handelLogOut = () => {
		localStorage.removeItem('authToken')
		localStorage.removeItem('user_id')
		dispatch(setAuthToken(token));
	}



	return (
		<div>
			{
				authToken ? <>
					<aside id="default-sidebar" className="fixed  left-0 z-40 w-64 h-screen transition-transform -translate-x-full sm:translate-x-0" aria-label="Sidebar">
						<div className="h-full px-3 py-10 overflow-y-auto bg-gray-50 dark:bg-gray-800">
							<ul className="space-y-2 font-medium">
								<li className='pb-2' onClick={handleDashboardBtn}>
									<a href="/" className="flex items-center space-x-3 rtl:space-x-reverse">
										<img src={logo} className="h-8" alt="Flowbite Logo" />
										<span className="self-center text-2xl font-semibold whitespace-nowrap dark:text-white">Household</span>
									</a>
								</li>
								<li onClick={() => toggleAsideNav('dashboard')}>
									<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
										<AiTwotoneAppstore />
										<span className="ms-3">Dashboard</span>
									</a>
								</li>

								<li onClick={() => toggleAsideNav('carts')}>
									<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
										<AiOutlineShoppingCart />
										<span className="ms-3">Carts</span>
									</a>
								</li>

								<li onClick={() => toggleAsideNav('orders')}>
									<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
										<AiOutlineShopping />
										<span className="ms-3">Orders</span>
									</a>
								</li>

								{
									profileData?.is_superuser === true &&
									<>

										<li onClick={() => toggleAsideNav('users')}>
											<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
												<AiOutlineUsergroupAdd />
												<span className="flex-1 ms-3 whitespace-nowrap">Users</span>
											</a>
										</li>

										<li onClick={() => toggleAsideNav('products')}>
											<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
												<AiFillShopping />
												<span className="flex-1 ms-3 whitespace-nowrap">Products</span>
											</a>
										</li>
									</>

								}

								<li onClick={() => toggleAsideNav('profile')}>
									<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
										<AiFillInfoCircle />
										<span className="flex-1 ms-3 whitespace-nowrap">Personal Info</span>
									</a>
								</li>

								<li onClick={handelLogOut}>
									<a href="#" className="flex items-center p-2 text-gray-900 rounded-lg dark:text-white hover:bg-gray-100 dark:hover:bg-gray-700 group">
										<svg className="flex-shrink-0 w-5 h-5 text-gray-500 transition duration-75 dark:text-gray-400 group-hover:text-gray-900 dark:group-hover:text-white" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 18 16">
											<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M1 8h11m0 0L8 4m4 4-4 4m4-11h3a2 2 0 0 1 2 2v10a2 2 0 0 1-2 2h-3" />
										</svg>
										<span className="flex-1 ms-3 whitespace-nowrap">Sign In</span>
									</a>
								</li>
							</ul>
						</div>
					</aside>

					<div className="p-4 sm:ml-64 bg-gray-100">

						{
							activeAsideBtn === 'dashboard' && (
								<div className='flex justify-center gap-10'>
									<RadialChart />
									<LevelsChart />
								</div>
							)
						}

						{/* show cart lists */}

						{
							activeAsideBtn === 'carts' && <CartList />
						}
						{
							activeAsideBtn === 'orders' && <Orders />
						}

						{/* show users table list  */}

						{
							activeAsideBtn === 'users' && <Users />
						}

						{/* show products  */}

						{
							activeAsideBtn === 'products' && <Products />
						}

						{/* update Profile  */}

						{
							activeAsideBtn === 'profile' && (
								<div className="bg-white max-w-4xl shadow overflow-hidden sm:rounded-lg">
									<div className="px-4 py-5 sm:px-6">
										<h3 className="text-lg leading-6 font-medium text-gray-900">
											User Profile
										</h3>
										<p className="mt-1 max-w-2xl text-sm text-gray-500">
											Details and informations about user.
										</p>
									</div>
									<div className="border-t border-gray-200">
										<dl>
											<div className="bg-gray-50 px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													Username
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													{profileData?.username}
												</dd>
											</div>
											<div className="bg-white px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													Full Name
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													{(profileData?.first_name) ? <>{profileData?.first_name} {profileData?.last_name}</> : 'None'}
												</dd>
											</div>
											<div className="bg-gray-50 px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													Email address
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													{profileData?.email}
												</dd>
											</div>
											<div className="bg-white px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													Access Type
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													{(profileData?.is_staff) || (profileData?.is_superuser) ? <>

														{(profileData?.is_superuser) ? <span className='text-sm text-green-500'>Admin</span> : <span className='text-sm text-yellow-500'>Staff</span>}

													</> : 'User'}
												</dd>
											</div>
											<div className="bg-white px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													Joined At
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													{new Date(profileData?.date_joined).toISOString().split("T")[0]}
												</dd>
											</div>
											<div className="bg-white px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													Last Login
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													{new Date(profileData?.date_joined).toISOString().split("T")[0]}
												</dd>
											</div>

											<div className="bg-gray-50 px-4 py-5 sm:grid sm:grid-cols-3 sm:gap-4 sm:px-6">
												<dt className="text-sm font-medium text-gray-500">
													About
												</dt>
												<dd className="mt-1 text-sm text-gray-900 sm:mt-0 sm:col-span-2">
													To get social media testimonials like these, keep your customers engaged with your social media accounts by posting regularly yourself
												</dd>
											</div>
										</dl>
									</div>
								</div>

							)
						}

					</div>
				</>
					: <></>
			}

		</div>
	)
}

export default Dashboard;