import React from 'react';

interface RatingProps {
  rating: number;
}

const Rating: React.FC<RatingProps> = ({ rating }) => {
  console.log(rating); // Check if the correct rating is logged here

  const totalStars = 5;
  const filledStars = '★'.repeat(rating);
  const unfilledStars = '☆'.repeat(totalStars - rating);

  return <span>{filledStars + unfilledStars}</span>;
};

export default Rating;
