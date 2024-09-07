import axios from 'axios'
import React, { useEffect, useState } from 'react'
import { useParams } from 'react-router-dom';

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





const ServiceDetials:React.FC=()=> {
	
	const [servicesSeller, setServicesSeller] = useState<SellerState[]>([])
	const{id}=useParams()


	useEffect(() => {
		const fetchServices = async () => {
			try {
				const response = await axios.get(`http://127.0.0.1:8000/service/list/${id}`)
				setServicesSeller(response.data)
				console.log("response", response.data);
			} catch (error) {
				console.error(error)
			}
		}
		fetchServices()
	}, [])


	// useEffect(() => {
	// 	const fetchServicesSeller = async () => {
	// 		try {
	// 			const response = await axios.get(`http://127.0.0.1:8000/auth/seller_profile/`)
	// 			setServicesSeller(response.data)
	// 			console.log("response", response.data);
	// 		} catch (error) {
	// 			console.error(error)
	// 		}
	// 	}
	// 	fetchServicesSeller()
	// }, [])

	return (
		<div>ServicesDetials {id}</div>
	)
}

export default ServiceDetials