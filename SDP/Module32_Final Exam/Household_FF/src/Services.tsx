import axios from 'axios'
import React, { useEffect, useState } from 'react'


interface ServicesListState {
	id: string,
	seller: number;
	service_title: string,
	category: string,
	price: number
	discription: string,
}

interface SellerState {
	user: number;
	service_category: string,
	phone: string,
	completed_jobs: number
}

const Services: React.FC = () => {
	const [servicesList, setServicesList] = useState<ServicesListState[]>([])
	const [servicesSeller, setServicesSeller] = useState<SellerState[]>([])

	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get('http://127.0.0.1:8000/service/list/')
				setServicesList(response.data)
				console.log("response", response.data);
			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [])

	useEffect(() => {
		const fetchServicesSeller = async () => {
			try {
				const response = await axios.get(`http://127.0.0.1:8000/auth/seller_profile/`)
				setServicesSeller(response.data)
				console.log("response", response.data);
			} catch (error) {
				console.error(error)
			}
		}
		fetchServicesSeller()
	}, [])


	return (
		<div>
			{
				servicesList.map((service, idx: number) => (
					<div key={idx} className="max-w-sm p-6 bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
						<a href="#">
							<h5 className="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">{service.service_title}</h5>
						</a>
						<div className="mb-3 font-normal text-gray-700 dark:text-gray-400">
							{
								servicesSeller.filter(seller => seller.user === service.seller).map((seller, idx) => (
									<>
										<p>{seller.service_category}</p>
										<p>{seller.completed_jobs}</p>
										<p>{seller.phone}</p>
									</>
								))
							}
						</div>
						<p className="mb-3 font-normal text-gray-700 dark:text-gray-400">{service.category}</p>
						<p className="mb-3 font-normal text-gray-700 dark:text-gray-400">{service.price}</p>
						<p className="mb-3 font-normal text-gray-700 dark:text-gray-400">{service.discription}</p>
						<a href="#" className="inline-flex items-center px-3 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">
							Read more
							<svg className="rtl:rotate-180 w-3.5 h-3.5 ms-2" aria-hidden="true" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 14 10">
								<path stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M1 5h12m0 0L9 1m4 4L9 9" />
							</svg>
						</a>
					</div>
				))
			}
		</div>
	)
}

export default Services