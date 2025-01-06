import axios from 'axios'
import React, { useEffect, useState } from 'react'

const Products:React.FC=()=> {
	const [allServices, setAllServices] = useState<[]>([])
	const [isDropDownOpen, setIsDropDownOpen] = useState(null)

	const getServices = async () => {
		try {
			const response = await axios.get(`https://household-backend-a4k7.onrender.com/services/list/`)
			setAllServices(response.data)

		} catch (error) {
			console.log(error);

		}
	}


	const toggleDropdown = (id: any) => {
		setIsDropDownOpen(isDropDownOpen === id ? null : id)
	}

	useEffect(()=>{
		getServices()
	},[])

	return (
		<table className="w-full text-sm text-left rtl:text-right text-gray-500 dark:text-gray-400">
		<thead className="text-xs text-gray-700 uppercase bg-gray-50 dark:bg-gray-700 dark:text-gray-400">
			<tr>
				<th scope="col" className="p-4">
					#id
				</th>
				<th scope="col" className="px-6 py-3">
					Seller
				</th>
				<th scope="col" className="px-6 py-3">
					Service
				</th>
				<th scope="col" className="px-6 py-3">
					Category
				</th>
				<th scope="col" className="px-6 py-3">
					Price
				</th>
				<th scope="col" className="px-6 py-3">
					Action
				</th>
			</tr>
		</thead>
		<tbody>



			{allServices?.map((service: any) => (
				<tr key={service?.id} className=" bg-white border-b dark:bg-gray-800 dark:border-gray-700 hover:bg-gray-50 dark:hover:bg-gray-600">
					<td className="w-4 p-4">
						{service?.id}
					</td>
					<td className="w-4 p-4">
						{service?.seller}
					</td>

					<td className="px-6 py-4">
						{service?.service_title}
					</td>
					<td className="px-6 py-4">
						{service?.categories.category}
					</td>

					<td className="px-6 py-4">
						{service?.price}
					</td>
					<td className="px-6 py-4 ">
						<div className=''>
							<button
								id={service?.id}
								onClick={() => toggleDropdown(service?.id)}
								className="inline-flex items-center text-gray-500 bg-white border border-gray-300 focus:outline-none hover:bg-gray-100 focus:ring-4 focus:ring-gray-100 font-medium rounded-lg text-sm px-3 py-1.5 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:bg-gray-700 dark:hover:border-gray-600 dark:focus:ring-gray-700"
								type="button"
							>
								<span className="sr-only">Action button</span>
								Action
								<svg className="w-2.5 h-2.5 ms-2.5" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 10 6">
									<path stroke="currentColor" strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M1 1l4 4 4-4" />
								</svg>
							</button>

							{isDropDownOpen === service?.id && (
								<div
									className="  z-10 bg-white divide-y divide-gray-100 rounded-lg shadow w-24 dark:bg-gray-700 dark:divide-gray-600"

								>
									<ul className="py-1  text-sm text-gray-700 dark:text-gray-200">
										<li className="pt-1">
											<button type="button" className="px-3 py-2 text-xs font-medium text-center text-white bg-green-700 rounded-lg hover:bg-green-800 focus:ring-4 focus:outline-none focus:ring-green-300 dark:bg-green-600 dark:hover:bg-green-700 dark:focus:ring-green-800">Freez Service</button>
										</li>
										<li className="pt-1">
											<button type="button" className="px-3 py-2 text-xs font-medium text-center text-white bg-red-700 rounded-lg hover:bg-red-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Delete Service</button>
										</li>
									</ul>
								</div>
							)}
						</div>
					</td>
				</tr>


			))}



		</tbody>
	</table>


	)
}

export default Products