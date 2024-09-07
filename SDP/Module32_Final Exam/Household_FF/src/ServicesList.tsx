import axios from 'axios'
import React, { useEffect, useState } from 'react'
import { FaUser } from "react-icons/fa6";
import { IoLogoUsd } from "react-icons/io5";
import { ImPriceTags } from "react-icons/im";
import { FaAngleRight } from "react-icons/fa6";
import { Link } from 'react-router-dom';


interface ServicesListState {
	id: number,
	seller: number;
	service_title: string,
	category: string,
	price: number
	discription: string,
}



const Services: React.FC = () => {
	const [servicesList, setServicesList] = useState<ServicesListState[]>([])
	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get('http://127.0.0.1:8000/service/list/')
				setServicesList(response.data)
			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [])

	

	return (
		<div className='grid grid-cols-3 gap-4'>
			{
				servicesList.map((service, idx: number) => (
					<div key={idx} className="max-w-sm p-6 bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
						<a href="#">
							<h5 className="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">{service.service_title}</h5>
						</a>
						<div className="flex gap-10 mb-1 font-normal text-gray-700 dark:text-gray-400">
								<p className="flex gap-2 items-center font-normal text-gray-700 dark:text-gray-400"><FaUser /> {service.seller}</p>
								<p className="flex gap-2 items-center font-normal text-gray-700 dark:text-gray-400"><ImPriceTags /> {service.category}</p>
						</div>
						<p className="flex  items-center mb-3 font-normal text-gray-700 dark:text-gray-400">Service Fee <IoLogoUsd /> {service.price}</p>
						<p className="mb-3 font-normal text-gray-700 dark:text-gray-400">{service.discription}</p>
						<Link to={`/services/${service.id}`} className=" flex gap-2 items-center inline-flex items-center px-3 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">
							Read more <FaAngleRight/>
						</Link>
					</div>
				))
			}
		</div>

	)
}

export default Services