import axios from 'axios'
import React, { useEffect, useState } from 'react'
import logo from '../assets/hs.png'
import toast from 'react-hot-toast'

const  Users:React.FC =()=> {

	const [allUsers, setAllUsers] = useState<[]>([])
	const [isDropDownOpen, setIsDropDownOpen] = useState(null)

	const authToken = localStorage.getItem('authToken')

	const getAllUsers = async () => {
		try {
			const response = await axios.get(`https://household-backend-a4k7.onrender.com/auth/users/`)
			setAllUsers(response.data)

		} catch (error) {
			console.log(error);

		}
	}

	const userRoleUpdate = async (id: number, is_staff: boolean, is_superuser: boolean) => {
		try {
			const response = await axios.patch(
				`https://household-backend-a4k7.onrender.com/auth/users/${id}/update_role/`,
				{ is_staff, is_superuser },
				{ headers: { Authorization: `Bearer ${authToken}` } }
			);
			if(!response){
				toast.error('Faild to update Role')
			}
			getAllUsers()
			// console.log('Role Update', response.data);

		} catch (error) {
			console.log(error);

		}
	}

	const toggleDropdown = (id: any) => {
		setIsDropDownOpen(isDropDownOpen === id ? null : id)
	}

	useEffect(()=> {
		getAllUsers()
	},[])

	return (
		<div className=" relative overflow-x-auto shadow-md sm:rounded-lg">
		<div className="flex items-center justify-between flex-column flex-wrap md:flex-row space-y-4 md:space-y-0 pb-4 bg-white dark:bg-gray-900">
			<label htmlFor="table-search" className="sr-only">Search</label>
			<div className="relative">
				<div className="absolute inset-y-0 rtl:inset-r-0 start-0 flex items-center ps-3 pointer-events-none">
					<svg className="w-4 h-4 text-gray-500 dark:text-gray-400" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 20 20">
						<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="m19 19-4-4m0-7A7 7 0 1 1 1 8a7 7 0 0 1 14 0Z" />
					</svg>
				</div>
				<input type="text" id="table-search-users" className="block p-2 ps-10 text-sm text-gray-900 border border-gray-300 rounded-lg w-80 bg-gray-50 focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Search for users" />
			</div>
		</div>

		<table className="w-full text-sm text-left rtl:text-right text-gray-500 dark:text-gray-400">
			<thead className="text-xs text-gray-700 uppercase bg-gray-50 dark:bg-gray-700 dark:text-gray-400">
				<tr>
					<th scope="col" className="p-4">
						#id
					</th>
					<th scope="col" className="px-6 py-3">
						Username
					</th>
					<th scope="col" className="px-6 py-3">
						Full Name
					</th>
					<th scope="col" className="px-6 py-3">
						Created At
					</th>
					<th scope="col" className="px-6 py-3">
						Status
					</th>
					<th scope="col" className="px-6 py-3">
						Access Type
					</th>
					<th scope="col" className="px-6 py-3">
						Action
					</th>
				</tr>
			</thead>
			<tbody>


				{
					allUsers?.map((user: any, idx: any) =>
						<tr key={idx} className=" bg-white border-b dark:bg-gray-800 dark:border-gray-700 hover:bg-gray-50 dark:hover:bg-gray-600">
							<td className="w-4 p-4">
								{user?.id}
							</td>

							<th scope="row" className="flex items-center px-6 py-4 text-gray-900 whitespace-nowrap dark:text-white">
								<img className="w-10 h-10 rounded-full" src={logo} alt="Jese image" />
								<div className="ps-3">
									<div className="text-base font-semibold">{user?.username}</div>
									<div className="font-normal text-gray-500">{user?.email}</div>
								</div>
							</th>
							<td className="px-6 py-4">
								{(user?.first_name) ? <>{user?.first_name} {user?.last_name}</> : 'None'}
							</td>
							<td className="px-6 py-4">
								{new Date(user?.date_joined).toISOString().split("T")[0]}
							</td>
							<td className="px-6 py-4">
								<div className="flex items-center">
									<div className="h-2.5 w-2.5 rounded-full bg-green-500 me-2"></div> {(user?.is_active) ? 'Active' : 'Deactive'}
								</div>
							</td>
							<td className="px-6 py-4">
								{(user?.is_staff) || (user?.is_superuser) ? <>

									{(user?.is_superuser) ? <span className='text-sm text-green-500'>Admin</span> : <span className='text-sm text-yellow-500'>Staff</span>}

								</> : 'User'}
							</td>
							<td className="px-6 py-4 ">
								<div className=''>
									<button
										id={user?.id}
										onClick={() => toggleDropdown(user?.id)}
										className="inline-flex items-center text-gray-500 bg-white border border-gray-300 focus:outline-none hover:bg-gray-100 focus:ring-4 focus:ring-gray-100 font-medium rounded-lg text-sm px-3 py-1.5 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:bg-gray-700 dark:hover:border-gray-600 dark:focus:ring-gray-700"
										type="button"
									>
										<span className="sr-only">Action button</span>
										Action
										<svg className="w-2.5 h-2.5 ms-2.5" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 10 6">
											<path stroke="currentColor" strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M1 1l4 4 4-4" />
										</svg>
									</button>

									{isDropDownOpen === user?.id && (
										<div
											className=" h-40 z-10 bg-white divide-y divide-gray-100 rounded-lg shadow w-25 dark:bg-gray-700 dark:divide-gray-600"

										>
											<ul className="py-1  text-sm text-gray-700 dark:text-gray-200">
												<li className="pt-1">
													<button onClick={() => userRoleUpdate(user?.id, true, true)} type="button" className="px-3 py-2 text-xs font-medium text-center text-white bg-green-700 rounded-lg hover:bg-green-800 focus:ring-4 focus:outline-none focus:ring-green-300 dark:bg-green-600 dark:hover:bg-green-700 dark:focus:ring-green-800">Make Admin</button>
												</li>
												<li className="pt-1">
													<button onClick={() => userRoleUpdate(user?.id, false, false)} type="button" className="px-3 py-2 text-xs font-medium text-center text-white bg-red-700 rounded-lg hover:bg-red-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Revok Admin</button>

												</li>
												<li className="pt-1">
													<button onClick={() => userRoleUpdate(user?.id, true, false)} type="button" className="px-3 py-2 text-xs font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Make Staff</button>
												</li>
											</ul>
											<div className="pt-1">
												<button onClick={() => userRoleUpdate(user?.id, false, false)} type="button" className="px-3 py-2 text-xs font-medium text-center text-white bg-red-700 rounded-lg hover:bg-red-800 focus:ring-4 focus:outline-none focus:ring-red-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Revok Staff</button>
											</div>
										</div>
									)}
								</div>
							</td>
						</tr>


					)
				}


			</tbody>
		</table>
	</div>
	)
}

export default Users