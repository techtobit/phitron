import axios from 'axios'
import React, { useEffect, useState } from 'react'
import { Link, useParams } from 'react-router-dom';
import { FaUser, FaAngleRight } from "react-icons/fa6";
import { IoLogoUsd } from "react-icons/io5";
import { ImPriceTags } from "react-icons/im";
import { FaPhoneSquareAlt, FaCartPlus } from "react-icons/fa";
import { MdCategory } from "react-icons/md";
import { BiTask } from "react-icons/bi";
import { RiShoppingBag4Fill } from "react-icons/ri";


interface ServicesDetailsState {
	id: number,
	seller: number;
	service_title: string,
	category: string,
	price: number
	discription: string,
}

interface SellerState {
	user: string;
	service_category: string,
	phone: string,
	completed_jobs: number
}


const ServiceDetials: React.FC = () => {

	const { id } = useParams()
	const [service, setService] = useState<ServicesDetailsState | null>(null)
	const [servicesSeller, setServicesSeller] = useState<SellerState | null>(null)

	const username = `${service?.seller}`



	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get(`http://127.0.0.1:8000/service/list/${id}`)
				setService(response.data)
			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [])


	useEffect(() => {
		const fetchServicesSeller = async () => {
			try {
				const response = await axios.get(`http://127.0.0.1:8000/auth/seller_profile/?username=${username}`)
				setServicesSeller(response.data[0])
			} catch (error) {
				console.error(error)
			}
		}
		fetchServicesSeller()
	}, [username])



		// Adding userId and ServiceId into Cart Model 
	const cartData= {
		"customer": service?.seller,
    "service":service?.id,
		"category": service?.category,
		"price": service?.price,
	}

		const addToCartService = async () => {
			try {
				const response = await axios.post(`http://127.0.0.1:8000/orders/cart/`, cartData, {
					headers:{
						"Content-Type": "application/json"
					}
				})
				console.log("cart - response -", response);
				
			} catch (error) {
				console.error(error)
			}
		}
		

	


	return (
		<div className='flex gap-10'>
			<div className=" w-full p-6 bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
				<a href="#">
					<h5 className="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">{service?.service_title}</h5>
				</a>
				<div className="flex gap-10 mb-1 font-normal text-gray-700 dark:text-gray-400">
					<p className="flex gap-2 items-center font-normal text-gray-700 dark:text-gray-400"><FaUser /> {service?.seller}</p>
					<p className="flex gap-2 items-center  font-normal text-gray-700 dark:text-gray-400"><ImPriceTags /> {service?.category}</p>
				</div>
				<p className="flex  items-center mb-3 font-normal text-gray-700 dark:text-gray-400">Service Fee <IoLogoUsd /> {service?.price} </p>
				<p className="mb-3 font-normal text-gray-700 dark:text-gray-400">{service?.discription}</p>

				<button onClick={addToCartService} className=" flex gap-2 items-center inline-flex items-center px-3 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">
					Add Cart <FaCartPlus/>
				</button>
				<Link to={`/services/cartList`} className=" flex gap-2 items-center ml-2 inline-flex items-center px-3 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">
					Check Carts <RiShoppingBag4Fill />
				</Link>
			</div>


			<div className="w-full max-w-sm bg-white border border-gray-200 rounded-lg shadow dark:bg-gray-800 dark:border-gray-700">
				<div className="flex flex-col items-center pb-10">
					<img className="w-24 h-24 mb-3 rounded-full shadow-lg" src="/docs/images/people/profile-picture-3.jpg" alt="Bonnie image" />
					<h5 className="mb-1 text-xl font-medium text-gray-900 dark:text-white">{servicesSeller?.user}</h5>
					<p className="flex gap-2 items-center text-sm text-gray-500 dark:text-gray-400">Category <MdCategory /> {servicesSeller?.service_category}</p>
					<p className="flex gap-2 items-center text-sm text-gray-500 dark:text-gray-400">Phone <FaPhoneSquareAlt/> {servicesSeller?.phone}</p>
					<p className="flex gap-2 items-center  text-sm text-gray-500 dark:text-gray-400">Completed Jobs <BiTask/> {servicesSeller?.completed_jobs}</p>
					<div className="flex mt-4 md:mt-6">
						<a href="#" className="inline-flex items-center px-4 py-2 text-sm font-medium text-center text-white bg-blue-700 rounded-lg hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Bookmark</a>
						<a href="#" className="py-2 px-4 ms-2 text-sm font-medium text-gray-900 focus:outline-none bg-white rounded-lg border border-gray-200 hover:bg-gray-100 hover:text-blue-700 focus:z-10 focus:ring-4 focus:ring-gray-100 dark:focus:ring-gray-700 dark:bg-gray-800 dark:text-gray-400 dark:border-gray-600 dark:hover:text-white dark:hover:bg-gray-700">Message</a>
					</div>
				</div>
			</div>

		</div>
	)
}

export default ServiceDetials